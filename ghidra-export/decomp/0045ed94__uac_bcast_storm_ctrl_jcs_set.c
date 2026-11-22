// func _uac_bcast_storm_ctrl_jcs_set @ 0045ed94 size=804

/* WARNING: Type propagation algorithm not settling */

void _uac_bcast_storm_ctrl_jcs_set(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *__format;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  if (bcast_storm_ctrl_debug_switch != 0) {
    printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : .............bcast_storm_ctrl_jcs_set begin............\n"
           ,"_uac_bcast_storm_ctrl_jcs_set",0xf7);
  }
  local_24 = 0;
  local_28 = 0;
  iVar3 = 0;
  uVar1 = json_object_object_get(param_1,"enable");
  _uac_json_object_to_integer(uVar1,&local_24);
  bcast_storm_ctrl_cfg_state_get(&local_28);
  if (local_24 != local_28) {
    if (bcast_storm_ctrl_debug_switch != 0) {
      printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : state changed(new value:%d,old value:%d).\n",
             "_uac_bcast_storm_ctrl_jcs_set",0x109,local_24,local_28);
    }
    iVar3 = 1;
    bcast_storm_ctrl_cfg_state_set(local_24);
  }
  uVar1 = json_object_object_get(param_1,"storm_rate");
  _uac_json_object_to_integer(uVar1,&local_24);
  bcast_storm_ctrl_cfg_rate_get(&local_28);
  if (local_24 != local_28) {
    if (bcast_storm_ctrl_debug_switch != 0) {
      printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : rate changed(new value:%d,old value:%d).\n",
             "_uac_bcast_storm_ctrl_jcs_set",0x114,local_24,local_28);
    }
    iVar3 = 1;
    bcast_storm_ctrl_cfg_rate_set(local_24);
  }
  if (bcast_storm_ctrl_debug_switch != 0) {
    printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : isChanged:%d\n","_uac_bcast_storm_ctrl_jcs_set",
           0x119,iVar3);
  }
  if (iVar3 == 0) {
LAB_0045ee6c:
    if (bcast_storm_ctrl_debug_switch == 0) {
      return;
    }
    uVar1 = 0x140;
    goto LAB_0045ef74;
  }
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar3 = serv_wtp_address_arg_init(&local_20);
  if (iVar3 == 0) {
    iVar3 = 1;
    iVar2 = apmngr_db_get_all_addr_by_capacity(&local_20,1,1,0x15f0000,1,0xe);
    if (iVar2 == 0) {
      if (bcast_storm_ctrl_debug_switch != 0) {
        iVar3 = local_18;
        printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : number of ap support capacity[%d]: %d\n",
               "_uac_bcast_storm_ctrl_jcs_set",0x12e,0xe,local_18);
      }
      if (local_18 == 0) {
        if (bcast_storm_ctrl_debug_switch != 0) {
          printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : no wtp support capacity[%d].\n",
                 "_uac_bcast_storm_ctrl_jcs_set",0x131,0xe,iVar3);
        }
      }
      else {
        iVar3 = _uac_bcast_storm_ctrl_pkt_send(&local_20);
        if (iVar3 == 0) {
          serv_wtp_address_arg_destroy(&local_20);
          if (bcast_storm_ctrl_debug_switch != 0) {
            printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : send bcast storm msgele success\n",
                   "_uac_bcast_storm_ctrl_jcs_set",0x13d);
          }
          goto LAB_0045ee6c;
        }
        if (bcast_storm_ctrl_error_switch != 0) {
          __format = "[BCAST_STORM_CTRL_ERROR]%s()/line %d : send packet failed.\n";
          uVar1 = 0x138;
          goto LAB_0045ef94;
        }
      }
    }
    else if (bcast_storm_ctrl_error_switch != 0) {
      __format = "[BCAST_STORM_CTRL_ERROR]%s()/line %d : get serv argv failed.\n";
      uVar1 = 0x12a;
      goto LAB_0045ef94;
    }
  }
  else if (bcast_storm_ctrl_error_switch != 0) {
    __format = "[BCAST_STORM_CTRL_ERROR]%s()/line %d : init serv argv failed.\n";
    uVar1 = 0x121;
LAB_0045ef94:
    printf(__format,"_uac_bcast_storm_ctrl_jcs_set",uVar1);
  }
  serv_wtp_address_arg_destroy(&local_20);
  if (bcast_storm_ctrl_debug_switch == 0) {
    return;
  }
  uVar1 = 0x146;
LAB_0045ef74:
  printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : .............bcast_storm_ctrl_jcs_set end............\n"
         ,"_uac_bcast_storm_ctrl_jcs_set",uVar1);
  return;
}

