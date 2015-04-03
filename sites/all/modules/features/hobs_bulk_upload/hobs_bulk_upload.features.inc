<?php
/**
 * @file
 * hobs_bulk_upload.features.inc
 */

/**
 * Implements hook_node_info().
 */
function hobs_bulk_upload_node_info() {
  $items = array(
    'upload_hobs_pdf' => array(
      'name' => t('Upload HOBS PDF'),
      'base' => 'node_content',
      'description' => t('Upload HOBS PDF'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
