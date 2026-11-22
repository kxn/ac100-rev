// func isAddrExcecuted @ 005d2c10 size=88

undefined4 isAddrExcecuted(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = &valid_addr_range;
  while( true ) {
    uVar2 = puVar1[1];
    if (*puVar1 <= param_1) {
      if (param_1 <= uVar2) {
        return 1;
      }
      uVar2 = puVar1[1];
    }
    if (uVar2 == 0) break;
    puVar1 = puVar1 + 0x23;
    if (puVar1 == (uint *)&udbg_help_list) {
      return 0;
    }
  }
  return 0;
}

