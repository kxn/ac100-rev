// func cJSON_get_int @ 00674a78 size=132

undefined4 cJSON_get_int(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) != 3)) {
    uVar1 = 0xffffffff;
    if (json_debug_switch != 0) {
      printf("[CJSON_DEBUG]%s()/%d Warning: obj is null or value type is unmatch.\n","cJSON_get_int"
             ,100);
    }
  }
  else {
    uVar1 = 0;
    *param_2 = *(undefined4 *)(param_1 + 0x14);
  }
  return uVar1;
}

