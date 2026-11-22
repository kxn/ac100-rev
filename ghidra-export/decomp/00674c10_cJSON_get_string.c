// func cJSON_get_string @ 00674c10 size=208

undefined4 cJSON_get_string(int param_1,char *param_2,size_t param_3)

{
  char *__format;
  undefined4 uVar1;
  
  if (((param_1 == 0) || (param_2 == (char *)0x0)) || ((int)param_3 < 0)) {
    if (json_debug_switch == 0) {
      return 0xffffffff;
    }
    uVar1 = 0x93;
    __format = "[CJSON_DEBUG]%s()/%d Warning: input error.\n";
  }
  else {
    if (*(int *)(param_1 + 0xc) == 4) {
      strncpy(param_2,*(char **)(param_1 + 0x10),param_3);
      return 0;
    }
    if (json_debug_switch == 0) {
      return 0xffffffff;
    }
    uVar1 = 0x98;
    __format = "[CJSON_DEBUG]%s()/%d Warning: value type is unmatch.\n";
  }
  printf(__format,"cJSON_get_string",uVar1);
  return 0xffffffff;
}

