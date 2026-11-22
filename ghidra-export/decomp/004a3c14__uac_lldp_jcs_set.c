// func _uac_lldp_jcs_set @ 004a3c14 size=1456

void _uac_lldp_jcs_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (uac_lldp_debug_switch != '\0') {
    printf("[UAC_LLDP_DEBUG]%s()/%d .............uac_lldp_jcs_set begin............\n",
           "_uac_lldp_jcs_set",0x103);
  }
  iVar1 = json_object_object_get(param_1,"is_first");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_lldp_jcs_set",0x10a);
        }
        goto LAB_004a3c8c;
      }
      uVar6 = json_object_get_double(iVar1);
      iVar1 = __fixunsdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    }
    if (iVar1 == 1) {
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      local_28 = 0;
      iVar2 = serv_wtp_address_arg_init(&local_34);
      if (iVar2 == 0) {
        iVar2 = apmngr_db_get_all_addr_by_capacity(&local_34,1,1,0x15f0000,1,0x25);
        if (iVar2 == 0) {
          if (uac_lldp_debug_switch != '\0') {
            iVar1 = local_2c;
            printf("[UAC_LLDP_DEBUG]%s()/%d number of ap support capacity[%d]: %d\n",
                   "_uac_lldp_jcs_set",0x121,0x25,local_2c);
          }
          if (local_2c == 0) {
            if (uac_lldp_debug_switch != '\0') {
              printf("[UAC_LLDP_DEBUG]%s()/%d no wtp support capacity[%d].\n","_uac_lldp_jcs_set",
                     0x124,0x25,iVar1);
            }
          }
          else {
            iVar1 = cw_pkt_buf_create(0xfa);
            if (iVar1 == 0) {
              if (uac_lldp_err_switch != '\0') {
                printf("[UAC_LLDP_ERROR]%s()/%d create capwap packet buffer failed.\n",
                       "_uac_lldp_pkt_send",0xe1);
              }
            }
            else {
              local_24 = 0;
              local_20 = 0;
              local_1c = 0;
              local_18 = 0;
              local_14 = 0;
              local_38 = 0;
              iVar2 = cw_parsed_pkt_create(7);
              if (iVar2 == 0) {
                if (uac_lldp_err_switch != '\0') {
                  printf("[UAC_LLDP_ERROR]%s()/%d malloc for CW_PARSED_PKT failed.\n",
                         "_uac_lldp_pkt_create",0xa1);
                }
LAB_004a3f04:
                if (uac_lldp_err_switch != '\0') {
                  pcVar4 = 
                  "[UAC_LLDP_ERROR]%s()/%d create broadcast storm control packet buffer failed.\n";
                  uVar5 = 0xe7;
LAB_004a41a0:
                  printf(pcVar4,"_uac_lldp_pkt_send",uVar5);
                }
              }
              else {
                local_24 = 0x12345678;
                local_20 = CONCAT22(0x67,local_20._2_2_);
                FUN_0051ad88(&local_1c);
                local_38 = 0;
                iVar3 = cw_service_msg_add(iVar2,0x25,&local_24,1,0x67,&local_38);
                if (iVar3 != 0) {
                  if (uac_lldp_err_switch != '\0') {
                    printf("[UAC_LLDP_ERROR]%s()/%d add msg element failed ret:%d.\n",
                           "_uac_lldp_pkt_create",0xb2,iVar3);
                  }
LAB_004a3ef8:
                  cw_parsed_pkt_destroy(iVar2);
                  goto LAB_004a3f04;
                }
                if (uac_lldp_debug_switch != '\0') {
                  printf("[UAC_LLDP_DEBUG]%s()/%d add msg element success.\n","_uac_lldp_pkt_create"
                         ,0xb5);
                }
                iVar3 = capwap_packet_assemble(iVar1,iVar2);
                if (iVar3 != 0) {
                  if (uac_lldp_err_switch != '\0') {
                    printf("[UAC_LLDP_ERROR]%s()/%d assemble packet buffer failed.\n",
                           "_uac_lldp_pkt_create",0xbb);
                  }
                  goto LAB_004a3ef8;
                }
                if (uac_lldp_debug_switch != '\0') {
                  printf("[UAC_LLDP_DEBUG]%s()/%d create parsed_pkt success.\n",
                         "_uac_lldp_pkt_create",0xbe);
                }
                cw_parsed_pkt_destroy(iVar2);
                if (uac_lldp_debug_switch != '\0') {
                  printf("[UAC_LLDP_DEBUG]%s()/%d create packet buffer success.\n",
                         "_uac_lldp_pkt_send",0xea);
                }
                iVar2 = serv_packet_send(&local_34,iVar1,1);
                if (iVar2 == 0) {
                  if (uac_lldp_debug_switch != '\0') {
                    printf("[UAC_LLDP_DEBUG]%s()/%d send packet buffer success.\n",
                           "_uac_lldp_pkt_send",0xf1);
                  }
                  cw_pkt_buf_destroy(iVar1);
                  serv_wtp_address_arg_destroy(&local_34);
                  if (uac_lldp_debug_switch != '\0') {
                    printf("[UAC_LLDP_DEBUG]%s()/%d send fit ap lldp msgele success\n",
                           "_uac_lldp_jcs_set",0x12f);
                  }
                  if (g_uac_lldp_timer != -1) {
                    FUN_00408060();
                    g_uac_lldp_timer = -1;
                  }
                  clear_uac_lldp_list(0);
                  FUN_004082d0(uac_lldp_mutex,0xffffffff);
                  g_is_continue = 1;
                  FUN_00407f30(uac_lldp_mutex);
                  g_uac_lldp_timer =
                       FUN_00408340(300,0,clear_uac_lldp_list,0,0,"_uac_lldp_timer_handle",0x89);
                  goto LAB_004a3c8c;
                }
                if (uac_lldp_err_switch != '\0') {
                  pcVar4 = "[UAC_LLDP_ERROR]%s()/%d send packet buffer failed.\n";
                  uVar5 = 0xee;
                  goto LAB_004a41a0;
                }
              }
              cw_pkt_buf_destroy(iVar1);
            }
            if (uac_lldp_err_switch != '\0') {
              pcVar4 = "[UAC_LLDP_ERROR]%s()/%d send packet failed.\n";
              uVar5 = 299;
              goto LAB_004a3e34;
            }
          }
        }
        else if (uac_lldp_err_switch != '\0') {
          pcVar4 = "[UAC_LLDP_ERROR]%s()/%d get serv argv failed.\n";
          uVar5 = 0x11d;
          goto LAB_004a3e34;
        }
      }
      else {
        if (uac_lldp_err_switch == '\0') goto LAB_004a3d74;
        pcVar4 = "[UAC_LLDP_ERROR]%s()/%d init serv argv failed.\n";
        uVar5 = 0x114;
LAB_004a3e34:
        printf(pcVar4,"_uac_lldp_jcs_set",uVar5);
      }
LAB_004a3d74:
      serv_wtp_address_arg_destroy(&local_34);
      if (uac_lldp_debug_switch == '\0') {
        return;
      }
      uVar5 = 0x138;
      goto LAB_004a3d24;
    }
  }
LAB_004a3c8c:
  if (uac_lldp_debug_switch != '\0') {
    printf("[UAC_LLDP_DEBUG]%s()/%d start a timer waiting %d seconds to timeout.\n",
           "_uac_lldp_timer_handle",0x8b,300);
  }
  if (uac_lldp_debug_switch == '\0') {
    return;
  }
  uVar5 = 0x133;
LAB_004a3d24:
  printf("[UAC_LLDP_DEBUG]%s()/%d .............uac_lldp_jcs_set end............\n",
         "_uac_lldp_jcs_set",uVar5);
  return;
}

