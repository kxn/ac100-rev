// func FUN_00674968 @ 00674968 size=8

undefined4 FUN_00674968(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) != 3)) {
    uVar1 = 0xffffffff;
    if (json_debug_switch != 0) {
      printf("[CJSON_DEBUG]%s()/%d Warning: obj is null or value type is unmatch.\n",
             "cJSON_get_int_8",0x44);
    }
  }
  else {
    uVar1 = 0;
    *param_2 = (char)*(undefined4 *)(param_1 + 0x14);
  }
  return uVar1;
}

