// func _apmngr_db_entry_printf_pf @ 00542df0 size=1

undefined4 _apmngr_db_entry_printf_pf(int param_1)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    apmngr_debug_template_print();
  }
  else {
    apmngr_debug_ap_print(param_1,0);
  }
  return 0;
}

