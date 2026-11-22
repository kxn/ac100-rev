// func multi_link_fini @ 00664c20 size=60

void multi_link_fini(void)

{
  if (g_multi_link_array != 0) {
    FUN_00407df0();
  }
  if (g_multi_link_config_changed_array != 0) {
    FUN_00407df0();
    return;
  }
  return;
}

