<?php
/**
 * @file
 * upload_pdf_for_bmi.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function upload_pdf_for_bmi_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:bmi-pdf-list
  $menu_links['main-menu:bmi-pdf-list'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'bmi-pdf-list',
    'router_path' => 'bmi-pdf-list',
    'link_title' => 'List BMI PDF ',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
  );
  // Exported menu link: main-menu:node/add/upload-pdf-for-bmi
  $menu_links['main-menu:node/add/upload-pdf-for-bmi'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/upload-pdf-for-bmi',
    'router_path' => 'node/add/upload-pdf-for-bmi',
    'link_title' => 'Upload BMI PDF',
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
    'weight' => -43,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('List BMI PDF ');
  t('Upload BMI PDF');


  return $menu_links;
}
