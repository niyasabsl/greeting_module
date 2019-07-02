<?php

/**
 * Returns the results of a node_load() for the specified node.
 *
 * @param $nid
 *   NID of the node we want to return.
 * @return
 *   Node object or FALSE if not found.
 */
function _greeting_resource_retrieve($nid) {
  $node = node_load($nid);
  if ($node && $node->type == 'greeting') {
    $uri = entity_uri('node', $node);
    $node->path = url($uri['path'], array('absolute' => TRUE));
    return $node;
  }
  return services_error(t('Greetig with id @nid could not be found', array('@nid' => $nid)), 404);
}

/**
 * Return an array of greeting nodes
 * @return
 *   An array of node objects.
 */
function _greeting_resource_list() {
  $node_select = db_select('node');
  $results = db_select('node', 'n')
    ->fields('n', array())
    ->condition('n.type', 'greeting')
    ->execute();
  return services_resource_build_index_list($results, 'node', 'nid');
}

/**
 * Creates a new greeting based on submitted values
 *
 * @param $node
 *   Array representing the attributes of a node
 * @return
 *   An associative array contained the new node's nid and, if applicable,
 *   the fully qualified URI to this resource.
 */
function _greeting_resource_create($node) {
  $node['type'] = 'greeting';
  $node = _node_resource_create($node);
  return $node;
}


/**
 * Updates a greeting node based on submitted values.
 * @param $nid
 *   Node ID of the node we're editing.
 * @param $node
 *   Array representing the attributes a node edit form would submit.
 * @return
 *   The node's nid.
 */
function _greeting_resource_update($nid, $node) {
  $old_node = node_load($nid);
  if ($old_node && $old_node->type == 'greeting') {
    $node = _node_resource_update($nid, $node);
    return $node;
  }
  return services_error(t('Greetig with id @nid could not be found', array('@nid' => $nid)), 404);
}


/**
 * Deletes a greeting node
 * @param $nid
 *   Node ID of the node we're deleting.
 */
function _greeting_resource_delete($nid) {
  $node = node_load($nid);
  if ($node && $node->type == 'greeting') {
    $node = _node_resource_delete($nid);
    return $node;
  }
  return services_error(t('Greetig with id @nid could not be found', array('@nid' => $nid)), 404);
}

/**
 * Publish/Unpublish greeting node based on submitted values.
 * @param $nid
 *   Node ID of the node we're editing.
 * @param $status
 *   status value 0 or 1
 * @return
 *   The node's nid.
 */
function _greeting_resource_publish($nid, $status) {
  $node = node_load($nid);
  if ($node && $node->type == 'greeting') {
    $node->status = $status;
    node_save($node);
    return array('nid' => $nid);
  }
  return services_error(t('Greetig with id @nid could not be found', array('@nid' => $nid)), 404);
}
