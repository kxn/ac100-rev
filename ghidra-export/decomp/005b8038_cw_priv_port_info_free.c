// func cw_priv_port_info_free @ 005b8038 size=88

undefined4 cw_priv_port_info_free(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 0x10);
  if (pcVar1 != (char *)0x0) {
    if ((*pcVar1 != '\0') && (*(int *)(pcVar1 + 4) != 0)) {
      FUN_00407df0();
      pcVar1[4] = '\0';
      pcVar1[5] = '\0';
      pcVar1[6] = '\0';
      pcVar1[7] = '\0';
    }
    FUN_00407df0(pcVar1);
  }
  return 0;
}

