<?php
/**
 * @file
 * imagine_blog.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function imagine_blog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function imagine_blog_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
