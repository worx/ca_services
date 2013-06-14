<?php
/**
 * @file
 * ca_services.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ca_services_user_default_roles() {
  $roles = array();

  // Exported role: services admin.
  $roles['services admin'] = array(
    'name' => 'services admin',
    'weight' => 6,
    'machine_name' => 'services_admin',
  );

  return $roles;
}
