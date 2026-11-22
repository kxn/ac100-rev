// func jcs_callback_register @ 00529250 size=416

undefined4 jcs_callback_register(char *param_1,uint param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (((param_1 == (char *)0x0) || (param_3 == 0)) || (3 < param_2)) {
    if (jcs_err_switch == 0) {
      return 0xffffffff;
    }
    uVar3 = 0x18a;
    pcVar2 = "[JCS_ERR]%s()/%d Invalid parameters.\n";
  }
  else {
    iVar1 = uac_hash_get(jcs_cb_tbl,param_1);
    if (iVar1 != 0) {
      *(int *)(iVar1 + (param_2 + 0x10) * 4 + 4) = param_3;
      return 0;
    }
    pcVar2 = (char *)uac_mem_malloc_my(0x54,0x196);
    if (pcVar2 == (char *)0x0) {
      if (jcs_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x199;
      pcVar2 = "[JCS_ERR]%s()/%d Malloc register entry failed.\n";
    }
    else {
      memset(pcVar2,0,0x54);
      strncpy(pcVar2,param_1,0x40);
      uVar3 = jcs_cb_tbl;
      *(int *)(pcVar2 + (param_2 + 0x10) * 4 + 4) = param_3;
      iVar1 = uac_hash_add(uVar3,pcVar2);
      if (iVar1 == 0) {
        return 0;
      }
      if (jcs_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x1a3;
      pcVar2 = "[JCS_ERR]%s()/%d Add to hash table failed.\n";
    }
  }
  printf(pcVar2,"jcs_callback_register",uVar3);
  return 0xffffffff;
}

