<?php

/**
 * @file
 * 
 * Contains the theme callbacks for our module
 */

/**
 * Theme callback for 'nextprev_links_pager'
 */
function theme_nextprev_links_pager($tags,$element,$parameters) {
$variables = array();
$variables['tags'] = $tags;
$variables['element'] = $element;
$variables['parameters'] = $parameters;
  $interval = 1;
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  global $pager_page_array, $pager_total;
 // print_r($pager_page_array);
  //print_r($pager_total);
   if ($pager_page_array[0] > 0) {

    // Add rel="prev".
    $page_new = pager_load_array($pager_page_array[0] - $interval, $element, $pager_page_array);

    $head_link = _nextprev_links_prep_rel_link($page_new, $element, $parameters, 'prev');
$check =    drupal_add_link($head_link);
  }

  if ($pager_page_array[0] < ($pager_total[0] - 1)) {

    // Add rel="next".
    $page_new = pager_load_array($pager_page_array[0] + $interval, $element, $pager_page_array);
    $head_link = _nextprev_links_prep_rel_link($page_new, $element, $parameters, 'next');
    drupal_add_link($head_link);
  }
  return theme('pager', array(),$element,$parameters);
}

function _nextprev_links_prep_rel_link($page_new, $element, $parameters = array(), $rel = 'next') {
  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    // Set defaults, if none given.
  if (!isset($query)) {
    $query = $_GET;
  }
  // If $exclude is empty, there is nothing to filter.

  }
  if ($query_pager = pager_get_querystring()) {
    $query = array_merge($query, $query_pager);
  }
  return array(
    'rel' => $rel,
    'href' => url(
      $_GET['q'],
      array(
        'query' => $query,
      )
    ),
  );
}
