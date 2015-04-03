<?php
/**
 * @file
 * hobs_bulk_upload.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hobs_bulk_upload_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_hobs_coefficient'
  $field_bases['field_hobs_coefficient'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hobs_coefficient',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  return $field_bases;
}
