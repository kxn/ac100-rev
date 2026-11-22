// func _wsta_intelligent_roam_start_acs_send @ 00483f7c size=1192

undefined4 _wsta_intelligent_roam_start_acs_send(undefined4 param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 local_c0;
  void *local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 uStack_a4;
  char local_a3;
  undefined1 auStack_80 [8];
  byte local_78;
  
  iVar2 = cw_pkt_buf_create(0xfa);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_c0 = 0;
  local_bc = (void *)0x0;
  memset(&uStack_a4,0,0x22);
  memset(auStack_80,0,0x54);
  if (param_2 == 0) {
LAB_00484058:
    if (wsta_roam_err_switch == '\0') goto LAB_00484068;
    pcVar7 = "[WSTA_ROAM_ERROR]%s()/%d create packet failed\n";
    uVar8 = 0x6c7;
  }
  else {
    iVar3 = apdb_radio_count_by_id(*(undefined4 *)(param_2 + 0x40),param_2 + 0x218);
    if (0 < iVar3) {
      iVar4 = wsta_roam_db_cfg_get(&uStack_a4);
      if (iVar4 == -1) {
        if (wsta_roam_err_switch != '\0') {
          pcVar7 = "[WSTA_ROAM_ERROR]%s()/%d stats_db_ctl_get failed\n";
          uVar8 = 0x661;
LAB_004841dc:
          printf(pcVar7,"_wsta_intelligent_roam_start_acs_create",uVar8);
        }
      }
      else if ((byte)(local_a3 - 1U) < 2) {
        iVar4 = cw_parsed_pkt_create(7);
        if (iVar4 == 0) {
          if (wsta_roam_err_switch != '\0') {
            printf("[WSTA_ROAM_ERROR]%s()/%d cw_parsed_pkt_create failed\n",
                   "_wsta_intelligent_roam_start_acs_create",0x66c);
          }
          iVar10 = -1;
        }
        else {
          local_b8 = 0x12345678;
          local_b4 = CONCAT22(0x9b,local_b4._2_2_);
          FUN_0051ad88(&local_b0);
          local_c0 = CONCAT13(100,CONCAT12((char)iVar3,local_c0._2_2_));
          local_bc = (void *)FUN_00408450(iVar3 << 3,0x676);
          if (local_bc == (void *)0x0) {
            iVar10 = -1;
            if (wsta_roam_err_switch != '\0') {
              pcVar7 = "[WSTA_ROAM_ERROR]%s()/%d malloc failed\n";
              uVar8 = 0x678;
              goto LAB_00484394;
            }
          }
          else {
            memset(local_bc,0,iVar3 << 3);
            iVar10 = 0;
            iVar11 = 1;
            do {
              uVar8 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_2 + 0x10),iVar11);
              iVar5 = rdmngr_db_rd_entry_get(uVar8,auStack_80);
              if (((iVar5 == 0) && (local_78 < 2)) &&
                 (pcVar7 = (&PTR_s_1_6_11_00696d90)[(char)local_78], pcVar7 != (char *)0x0)) {
                iVar9 = iVar10 * 8;
                *(char *)((int)local_bc + iVar9) = (char)iVar10;
                sVar6 = strlen(pcVar7);
                pvVar1 = local_bc;
                *(char *)((int)local_bc + iVar9 + 1) = (char)sVar6;
                iVar5 = FUN_00408450(*(byte *)((int)local_bc + iVar9 + 1) + 1,0x685);
                *(int *)((int)pvVar1 + iVar9 + 4) = iVar5;
                if (iVar5 == 0) {
                  iVar10 = -1;
                  if (wsta_roam_err_switch == '\0') goto LAB_00484360;
                  pcVar7 = "[WSTA_ROAM_ERROR]%s()/%d malloc failed\n";
                  uVar8 = 0x687;
                  goto LAB_00484394;
                }
                memset(*(void **)((int)local_bc + iVar9 + 4),0,
                       *(byte *)((int)local_bc + iVar9 + 1) + 1);
                strncpy(*(char **)((int)local_bc + iVar9 + 4),pcVar7,
                        *(byte *)((int)local_bc + iVar9 + 1) + 1);
              }
              iVar11 = iVar11 + 1;
              iVar10 = iVar10 + 1;
            } while (iVar11 <= iVar3);
            iVar10 = cw_service_msg_add(iVar4,0x25,&local_b8,1,0x9b,&local_c0);
            if (iVar10 == 0) {
              iVar11 = capwap_packet_assemble(iVar2,iVar4);
              iVar10 = 0;
              if ((iVar11 == -1) && (iVar10 = -1, wsta_roam_err_switch != '\0')) {
                pcVar7 = "[WSTA_ROAM_ERROR]%s()/%d capwap_packet_assemble failed\n";
                uVar8 = 0x6a0;
                goto LAB_00484394;
              }
            }
            else {
              iVar10 = -1;
              if (wsta_roam_err_switch != '\0') {
                pcVar7 = "[WSTA_ROAM_ERROR]%s()/%d cw_service_msg_add failed\n";
                uVar8 = 0x699;
LAB_00484394:
                iVar10 = -1;
                printf(pcVar7,"_wsta_intelligent_roam_start_acs_create",uVar8);
              }
            }
          }
LAB_00484360:
          cw_parsed_pkt_destroy(iVar4);
        }
        if (local_bc != (void *)0x0) {
          iVar4 = 0;
          iVar11 = 1;
          do {
            iVar11 = iVar11 + 1;
            if (*(int *)((int)local_bc + iVar4 + 4) != 0) {
              FUN_00407df0();
              *(undefined4 *)((int)local_bc + iVar4 + 4) = 0;
            }
            iVar4 = iVar4 + 8;
          } while (iVar11 <= iVar3);
          FUN_00407df0(local_bc);
        }
        if (iVar10 == 0) goto LAB_00484138;
      }
      else if (wsta_roam_err_switch != '\0') {
        pcVar7 = "[WSTA_ROAM_ERROR]%s()/%d invalid ap mode\n";
        uVar8 = 0x666;
        goto LAB_004841dc;
      }
      goto LAB_00484058;
    }
LAB_00484138:
    iVar3 = serv_packet_send(param_1,iVar2,1);
    if (iVar3 != -1) {
      cw_pkt_buf_destroy(iVar2);
      return 0;
    }
    if (wsta_roam_err_switch == '\0') goto LAB_00484068;
    pcVar7 = "[WSTA_ROAM_ERROR]%s()/%d send packet failed.\n";
    uVar8 = 0x6cd;
  }
  printf(pcVar7,"_wsta_intelligent_roam_start_acs_send",uVar8);
LAB_00484068:
  cw_pkt_buf_destroy(iVar2);
  return 0xffffffff;
}

