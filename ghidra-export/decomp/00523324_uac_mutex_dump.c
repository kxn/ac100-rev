// func uac_mutex_dump @ 00523324 size=28

void uac_mutex_dump(void)

{
  uac_mutex_traverse_list(_uac_print_mutex);
  return;
}

