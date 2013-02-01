<?php

/**
 * @file
 * CA_Services admin system, which overrides the default feature settings.
 *
 * Will allow us to make visual changes to the feature without overriding the
 * actual feature.
 */

/**
 * Defines the menu for overriding services feature settings.
 *
 * @return
 *   Fully formed Form API array.
 */
function ca_services_settings_form() {
  $form = array();

  $form['ca_services_panel_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('ca_services_panel_title', 'Services'),
    '#required' => TRUE,
    '#description' => t('What would you like the panel title to be?'),
  );
  $form['ca_services_menu_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu Title'),
    '#default_value' => variable_get('ca_services_menu_title', 'Services'),
    '#required' => TRUE,
    '#description' => t('What would you like the menu title to be?'),
  );
  $form['ca_services_list_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Case Studies per page'),
    '#default_value' => variable_get('ca_services_list_count', 5),
    '#required' => TRUE,
    '#description' => t('How many case studies would you like displayed per page?'),
  );
  $form['ca_services_block_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Case Studies in the block'),
    '#default_value' => variable_get('ca_services_block_count', 1),
    '#required' => TRUE,
    '#description' => t('How many case studies would you like displayed in the block?'),
  );
  $form['ca_services_list_template'] = array(
    '#type' => 'select',
    '#title' => t('Services\'s list template'),
    '#options' => array(
      'ca_services_list_template_one' => t('Template one'),
      'ca_services_list_template_two' => t('Template two'),
      'ca_services_list_template_three' => t('Template three'),
    ),
    '#required' => TRUE,
    '#default_value' => variable_get('ca_services_list_template', 'ca_services_list_template_one'),
  );
  $form['ca_services_node_template'] = array(
    '#type' => 'select',
    '#title' => t('Services\'s node template'),
    '#options' => array(
      'ca_services_node_template_one' => t('Template one'),
      'ca_services_node_template_two' => t('Template two'),
      'ca_services_node_template_three' => t('Template three'),
    ),
    '#required' => TRUE,
    '#default_value' => variable_get('ca_services_node_template', 'ca_services_node_template_one'),
  );
  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  // We are adding the system_settings_form_submit manually instead of
  // returning system_settings_form($form) in our return statement.
  // This allows for us to add our submit handler after the
  // system_settings_form_submit. hook_form_alter could not handle this for us.
  $form['#submit'][] = 'system_settings_form_submit';
  $form['#submit'][] = 'ca_services_settings_form_submit';

  return $form;
}

/**
 * Handles form submission data from 'ca_services_settings_form'.
 *
 * Determines if we should rebuild the menu router based on form data.
 */
function ca_services_settings_form_submit($form, &$form_state) {
  $old_title = $form['ca_services_menu_title']['#default_value'];
  $new_title = $form_state['values']['ca_services_menu_title'];
  if ($old_title != $new_title) {
    menu_rebuild();
  }
}
