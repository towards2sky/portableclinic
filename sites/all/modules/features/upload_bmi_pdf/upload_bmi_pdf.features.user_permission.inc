<?php
/**
 * @file
 * upload_bmi_pdf.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function upload_bmi_pdf_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create upload_bmi_pdf content'.
  $permissions['create upload_bmi_pdf content'] = array(
    'name' => 'create upload_bmi_pdf content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any upload_bmi_pdf content'.
  $permissions['delete any upload_bmi_pdf content'] = array(
    'name' => 'delete any upload_bmi_pdf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own upload_bmi_pdf content'.
  $permissions['delete own upload_bmi_pdf content'] = array(
    'name' => 'delete own upload_bmi_pdf content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any upload_bmi_pdf content'.
  $permissions['edit any upload_bmi_pdf content'] = array(
    'name' => 'edit any upload_bmi_pdf content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own upload_bmi_pdf content'.
  $permissions['edit own upload_bmi_pdf content'] = array(
    'name' => 'edit own upload_bmi_pdf content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
