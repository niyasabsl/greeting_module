<?php

/**
 * @file
 * greeting_custom_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function greeting_custom_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_node_info().
 */
function greeting_custom_content_type_node_info() {
  $items = array(
    'greeting' => array(
      'name' => t('Greeting'),
      'base' => 'node_content',
      'description' => t('Creates a new greeting'),
      'has_title' => '1',
      'title_label' => t('Greeting title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
