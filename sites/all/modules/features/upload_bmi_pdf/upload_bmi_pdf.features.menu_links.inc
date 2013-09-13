<?php
/**
 * @file
 * upload_bmi_pdf.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function upload_bmi_pdf_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:list-bmi-pdf
  $menu_links['main-menu:list-bmi-pdf'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'list-bmi-pdf',
    'router_path' => 'list-bmi-pdf',
    'link_title' => 'List BMI PDF',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'node/add/upload-bmi-pdf',
  );
  // Exported menu link: main-menu:node/add/upload-bmi-pdf
  $menu_links['main-menu:node/add/upload-bmi-pdf'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/upload-bmi-pdf',
    'router_path' => 'node/add/upload-bmi-pdf',
    'link_title' => 'Upload BMI PDF',
    'options' => array(
      'attributes' => array(
        'title' => 'pdf upload for bmi ',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'node/add/upload-bmi-pdf',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('List BMI PDF');
  t('Upload BMI PDF');


  return $menu_links;
}
