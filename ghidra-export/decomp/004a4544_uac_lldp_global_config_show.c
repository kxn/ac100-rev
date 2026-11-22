// func uac_lldp_global_config_show @ 004a4544 size=1

void uac_lldp_global_config_show(void)

{
  printf("uac_lldp_err_switch :%d\n",(int)uac_lldp_err_switch);
  printf("uac_lldp_debug_switch :%d\n",(int)uac_lldp_debug_switch);
  (*(code *)PTR_puts_00758f90)("================================");
  return;
}

