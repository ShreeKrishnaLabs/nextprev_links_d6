<?php

/**
 * @file
 * 
 * Views plugin implementations for Next Prev Links.
**/

  require_once(drupal_get_path('module', 'views') . '/plugins/views_plugin_pager_full.inc');  
/**
 * The plugin to provide the Next Prev Links.
 *
 * @ingroup views_pager_plugins
 */
class nextprev_links_pager extends views_plugin_pager_full {

  /**
   * Overrides views_plugin_pager_full::render().
   *
   * Overrides the full pager renderer by changing the theme function
   * and leaving out variables that are not used in the mini pager.
   */
  function render($input) {
     $pager_theme = views_theme_functions('nextprev_links_pager', $this->view, $this->display);
    return theme($pager_theme, $input, $this->options['items_per_page'], $this->options['id']);
  }
}
