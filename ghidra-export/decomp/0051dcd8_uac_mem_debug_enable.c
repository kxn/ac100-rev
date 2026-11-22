// func uac_mem_debug_enable @ 0051dcd8 size=1

void uac_mem_debug_enable(void)

{
  int in_t9;
  
  **(undefined4 **)(in_t9 + 0x23b778) = 1;
  return;
}

