// func cJSON_get_str2int_8 @ 00674ce0 size=204

undefined4 cJSON_get_str2int_8(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_50 [68];
  
  memset(acStack_50,0,0x40);
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) != 4)) {
    uVar2 = 0xffffffff;
    if (json_debug_switch != 0) {
      printf("[CJSON_DEBUG]%s()/%d Warning: obj is null or value type is unmatch.\n",
             "cJSON_get_str2int_8",0xa8);
    }
  }
  else {
    uVar2 = 0;
    strncpy(acStack_50,*(char **)(param_1 + 0x10),0x40);
    iVar1 = atoi(acStack_50);
    *param_2 = (char)iVar1;
  }
  return uVar2;
}

