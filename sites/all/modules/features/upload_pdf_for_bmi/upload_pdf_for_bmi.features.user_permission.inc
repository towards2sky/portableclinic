<?php
/**
 * @file
 * upload_pdf_for_bmi.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function upload_pdf_for_bmi_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create upload_pdf_for_bmi content'.
  $permissions['create upload_pdf_for_bmi content'] = array(
    'name' => 'create upload_pdf_for_bmi content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any upload_pdf_for_bmi content'.
  $permissions['delete any upload_pdf_for_bmi content'] = array(
    'name' => 'delete any upload_pdf_for_bmi content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own upload_pdf_for_bmi content'.
  $permissions['delete own upload_pdf_for_bmi content'] = array(
    'name' => 'delete own upload_pdf_for_bmi content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any upload_pdf_for_bmi content'.
  $permissions['edit any upload_pdf_for_bmi content'] = array(
    'name' => 'edit any upload_pdf_for_bmi content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own upload_pdf_for_bmi content'.
  $permissions['edit own upload_pdf_for_bmi content'] = array(
    'name' => 'edit own upload_pdf_for_bmi content',
    'roles' => array(
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
