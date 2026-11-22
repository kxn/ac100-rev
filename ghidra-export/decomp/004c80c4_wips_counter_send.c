// func wips_counter_send @ 004c80c4 size=740

void wips_counter_send(void *param_1,int param_2,int param_3)

{
  char *__s;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *__format;
  int iVar6;
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if ((param_2 != 0) && (param_1 != (void *)0x0)) {
    __s = (char *)FUN_00408450(0x8000,0x477);
    iVar1 = json_object_new_array();
    if ((__s == (char *)0x0) || (iVar6 = 0, iVar1 == 0)) {
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d out of memory\n","wips_counter_send",0x47b);
      }
      if (__s != (char *)0x0) {
        FUN_00407df0(__s);
      }
      if (iVar1 != 0) {
        json_object_put(iVar1);
      }
    }
    else {
      while (iVar6 < param_2) {
        iVar2 = json_object_new_object();
        if (iVar2 == 0) {
          if (sensor_err_switch != '\0') {
            printf("[SENSOR_ERROR]%s()/%d malloc json obj failed.\n","wips_counter_send",0x483);
          }
LAB_004c8204:
          iVar6 = iVar6 + 1;
          param_1 = (void *)((int)param_1 + 6);
        }
        else {
          memcpy(&local_48,param_1,6);
          wips_mac2str(&local_48,&local_40);
          uVar3 = json_object_new_string(&local_40);
          json_object_object_add(iVar2,"bssid",uVar3);
          if (param_3 == 0) {
LAB_004c81f8:
            json_object_array_add(iVar1,iVar2);
            goto LAB_004c8204;
          }
          iVar4 = json_object_new_array(iVar1);
          if (iVar4 == 0) {
            if (sensor_err_switch != '\0') {
              printf("[SENSOR_ERROR]%s()/%d out of memory\n","wips_counter_send",0x491);
            }
          }
          else {
            iVar5 = FUN_00407fa0(g_counter_info_hash,&local_48);
            if (iVar5 != 0) {
              wips_channel_list_to_json(iVar5 + 0x14,iVar4);
              json_object_object_add(iVar2,"channel",iVar4);
              goto LAB_004c81f8;
            }
            if (sensor_err_switch != '\0') {
              printf("[SENSOR_ERROR]%s()/%d get counter info from hash failed.\n",
                     "wips_counter_send",0x498);
            }
            json_object_put(iVar2);
            iVar2 = iVar4;
          }
          iVar6 = iVar6 + 1;
          json_object_put(iVar2);
          param_1 = (void *)((int)param_1 + 6);
        }
      }
      if (param_3 == 0) {
        uVar3 = json_object_to_json_string_ext(iVar1,0);
        __format = 
        "{\"method\":\"do\",\"wireless_counter\":{\"del_dev\":{\"radio_id\":\"1\",\"dev_list\":%s}}}"
        ;
      }
      else {
        uVar3 = json_object_to_json_string_ext(iVar1,0);
        __format = 
        "{\"method\":\"do\",\"wireless_counter\":{\"add_dev\":{\"radio_id\":\"1\",\"dev_list\":%s}}}"
        ;
      }
      sprintf(__s,__format,uVar3);
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d wips_counter_send: %s\n","wips_counter_send",0x4ae,__s);
      }
      sensor_pkt_tdcp_send_all(__s);
      json_object_put(iVar1);
      FUN_00407df0(__s);
    }
  }
  return;
}

