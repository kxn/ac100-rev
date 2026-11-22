// func uac_mem_debug_disable @ 0051dcf4 size=24

void uac_mem_debug_disable(void)

{
  mem_debug_switch = 0;
  return;
}

