// func rdmngr_trigger_radio_onoff_nms_event @ 006137c0 size=592

void rdmngr_trigger_radio_onoff_nms_event(uint param_1,int param_2)

{
  undefined2 uVar4;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_370;
  uint local_36c;
  undefined *local_368 [2];
  char local_360 [20];
  char acStack_34c [100];
  undefined1 auStack_2e8 [72];
  byte local_2a0;
  byte local_29f;
  byte local_29e;
  byte local_29d;
  byte local_29c;
  byte local_29b;
  
  local_360[0] = '\0';
  local_360[1] = '\0';
  local_360[2] = '\0';
  local_360[3] = '\0';
  local_360[4] = '\0';
  local_360[5] = '\0';
  local_360[6] = '\0';
  local_360[7] = '\0';
  local_360[8] = '\0';
  local_360[9] = '\0';
  local_360[10] = '\0';
  local_360[0xb] = '\0';
  local_360[0xc] = '\0';
  local_360[0xd] = '\0';
  local_360[0xe] = '\0';
  local_360[0xf] = '\0';
  local_360[0x10] = '\0';
  local_360[0x11] = '\0';
  memset(acStack_34c,0,100);
  local_36c = 0;
  local_370 = 0;
  local_368[0] = &DAT_0069b2ac;
  local_368[1] = &DAT_0069b2b0;
  memset(auStack_2e8,0,0x2d8);
  if (param_2 == 0) {
    uVar4 = rdmngr_db_generate_ap_id(param_1);
    iVar1 = apmngr_db_entry_get_by_id(uVar4,auStack_2e8);
    if ((((iVar1 == 0) &&
         (iVar1 = rdmngr_db_get_freq_band_idx(param_1,&local_36c,&local_370), iVar1 == 0)) &&
        (-1 < (int)local_36c)) && (local_36c < 2)) {
      iVar1 = json_object_new_object();
      if (iVar1 == 0) {
        if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[RDMNGR_ERROR]%s()/%d malloc obj failed.\n","rdmngr_trigger_radio_onoff_nms_event"
                 ,0xa2a);
        }
      }
      else {
        sprintf(local_360,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a0,(uint)local_29f,
                (uint)local_29e,(uint)local_29d,(uint)local_29c,(uint)local_29b);
        uVar2 = json_object_new_string(local_360);
        json_object_object_add(iVar1,"devMac",uVar2);
        snprintf(acStack_34c,100,"%s%d",local_368[local_36c],local_370);
        uVar2 = json_object_new_string(acStack_34c);
        json_object_object_add(iVar1,"band",uVar2);
        uVar2 = json_object_new_int(param_1 & 0xf);
        json_object_object_add(iVar1,"radioId",uVar2);
        json_object_to_json_string_ext(iVar1,0);
        nms_event_notify(0x989a7b);
        if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d trigger_radio_onoff_nms_event for mac %s/%d!\n",
                 "rdmngr_trigger_radio_onoff_nms_event",0xa37,local_360,param_1);
        }
        json_object_put(iVar1);
      }
    }
  }
  return;
}

