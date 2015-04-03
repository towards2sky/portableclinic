<?php
/**
 * @file
 * hobs_bulk_upload.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hobs_bulk_upload_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-upload_hobs_pdf-field_hobs_coefficient'
  $field_instances['node-upload_hobs_pdf-field_hobs_coefficient'] = array(
    'bundle' => 'upload_hobs_pdf',
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
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hobs_coefficient',
    'label' => 'Hobs coefficient',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Hobs coefficient');

  return $field_instances;
}
