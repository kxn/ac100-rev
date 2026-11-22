// func uac_wservice_help_reg @ 005e00f0 size=20

void uac_wservice_help_reg(void)

{
  udbg_help_register("wservice","wserv_debug_help()");
  return;
}

