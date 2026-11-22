// func trigger_sta_overload_nms_event @ 006387ec size=328

void trigger_sta_overload_nms_event(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_28 [28];
  
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  local_28[0x10] = '\0';
  local_28[0x11] = '\0';
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[error]%s(): %d  -> malloc obj failed.\r\n","trigger_sta_overload_nms_event",
             0x637);
    }
  }
  else {
    sprintf(local_28,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,(uint)param_1[1],
            (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    uVar2 = json_object_new_string(local_28);
    json_object_object_add(iVar1,"devMac",uVar2);
    uVar2 = json_object_to_json_string_ext(iVar1,0);
    nms_event_notify(0x989a7c);
    json_object_put(iVar1);
    if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[debug]%s(): %d  -> trigger_sta_overload_nms_event for mac %s!\r\n",
             "trigger_sta_overload_nms_event",0x641,local_28,uVar2);
    }
  }
  return;
}

