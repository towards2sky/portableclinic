<?php
/**
 * @file
 * upload_pdf_for_bmi.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function upload_pdf_for_bmi_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-upload_pdf_for_bmi-field_pdf_package'
  $field_instances['node-upload_pdf_for_bmi-field_pdf_package'] = array(
    'bundle' => 'upload_pdf_for_bmi',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdf_package',
    'label' => 'PDF Package',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('PDF Package');

  return $field_instances;
}
