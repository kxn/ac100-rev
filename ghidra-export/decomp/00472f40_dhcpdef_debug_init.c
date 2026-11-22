// func dhcpdef_debug_init @ 00472f40 size=20

void dhcpdef_debug_init(void)

{
  udbg_help_register("dhcp_defend","dhcpdef_debug_help()");
  return;
}

