// func wips_wserv_whitelist_to_json @ 004c6174 size=332

void wips_wserv_whitelist_to_json(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char acStack_110 [256];
  
  memset(acStack_110,0,0x100);
  snprintf(acStack_110,0x100,"%d",g_wips_info_max_size + 1 + *(int *)(param_1 + 0x80));
  uVar1 = json_object_new_string(acStack_110);
  json_object_object_add(param_2,"whitelist_id",uVar1);
  uVar1 = json_object_new_string("00-00-00-00-00-00");
  json_object_object_add(param_2,"mac",uVar1);
  uVar1 = json_object_new_string(param_1 + 0x130);
  json_object_object_add(param_2,"ssid",uVar1);
  memset(acStack_110,0,0x100);
  snprintf(acStack_110,0x100,"%d",*(undefined4 *)(param_1 + 300));
  uVar1 = json_object_new_string(acStack_110);
  json_object_object_add(param_2,"ssid_encode",uVar1);
  memset(acStack_110,0,0x100);
  snprintf(acStack_110,0x100,"%d",0);
  uVar1 = json_object_new_string(acStack_110);
  json_object_object_add(param_2,"editable",uVar1);
  return;
}

