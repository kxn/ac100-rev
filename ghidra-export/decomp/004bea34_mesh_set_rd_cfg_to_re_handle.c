// func mesh_set_rd_cfg_to_re_handle @ 004bea34 size=1468

undefined4 mesh_set_rd_cfg_to_re_handle(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  undefined1 auStack_3b8 [9];
  char local_3af;
  undefined1 local_3ae;
  short local_3ac;
  char local_39f;
  undefined2 local_39e;
  undefined1 auStack_364 [12];
  undefined2 local_358;
  undefined1 auStack_310 [16];
  undefined2 local_300;
  undefined4 local_2d0;
  undefined1 auStack_f8 [192];
  int local_38;
  int local_34;
  int local_30;
  
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d mesh_set_rd_cfg_to_re_handle ENTER\n","mesh_set_rd_cfg_to_re_handle"
           ,0x3d9);
  }
  uVar5 = 0;
  if (param_1 != 0) {
    memset(auStack_364,0,0x54);
    memset(auStack_3b8,0,0x54);
    memset(auStack_310,0,0x2d8);
    iVar2 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x18),auStack_310);
    uVar5 = 1;
    if (iVar2 != -1) {
      local_34 = apdb_radio_count_by_id(local_2d0,auStack_f8);
      local_30 = param_1 + 0x218;
      local_38 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),local_30);
      uVar7 = 1;
      while (uVar5 = 0, (int)uVar7 <= local_38) {
        uVar5 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),uVar7);
        iVar2 = rdmngr_db_get_rd_freq_band(uVar5);
        iVar3 = rdmngr_db_rd_entry_get(uVar5,auStack_364);
        if (iVar3 == -1) {
          return 1;
        }
        cVar8 = (char)uVar7;
        if (iVar2 == 0) {
          if (param_2 == 2) {
            uVar4 = rdmngr_db_generate_rd_id(local_300,uVar7);
            iVar2 = rdmngr_db_rd_entry_get(uVar4,auStack_3b8);
            if (iVar2 != 0) {
              cVar8 = cVar8 + '\x01';
              goto LAB_004bebcc;
            }
            if (mesh_debug_switch == '\0') {
              iVar2 = (int)local_39f;
            }
            else {
              uVar1 = *(ushort *)(param_1 + 0x10);
              uVar4 = 0x404;
LAB_004bee5c:
              printf("[MESH_DEBUG]%s()/%d modify ap_id=%d, rd_id=%d\n",
                     "mesh_set_rd_cfg_to_re_handle",uVar4,(uint)uVar1,uVar5);
              iVar2 = (int)local_39f;
            }
LAB_004bed10:
            uVar7 = uVar7 & 0xff;
LAB_004bed30:
            uVar5 = 1;
          }
          else {
            uVar4 = rdmngr_db_generate_rd_id(local_300,uVar7);
            iVar2 = rdmngr_db_rd_entry_get(uVar4,auStack_3b8);
            if (iVar2 != 0) {
              cVar8 = cVar8 + '\x01';
              goto LAB_004bebcc;
            }
            if (mesh_debug_switch == '\0') {
              iVar2 = (int)local_39f;
            }
            else {
              uVar6 = (uint)*(ushort *)(param_1 + 0x10);
              uVar4 = 0x40d;
LAB_004bed70:
              printf("[MESH_DEBUG]%s()/%d modify ap_id=%d, rd_id=%d\n",
                     "mesh_set_rd_cfg_to_re_handle",uVar4,uVar6,uVar5);
              iVar2 = (int)local_39f;
            }
LAB_004beb94:
            uVar7 = uVar7 & 0xff;
LAB_004bebb4:
            uVar5 = 0;
          }
          FUN_004bde50(auStack_364,(int)local_3af,local_3ae,(int)local_3ac,iVar2,local_39e,param_1,
                       uVar7,uVar5,param_3);
          cVar8 = cVar8 + '\x01';
        }
        else {
          if (iVar2 != 1) {
            cVar8 = cVar8 + '\x01';
            goto LAB_004bebcc;
          }
          if (param_2 == 2) {
            if ((local_34 != 2) || (local_38 != 3)) {
              uVar4 = rdmngr_db_generate_rd_id(local_300,uVar7);
              iVar2 = rdmngr_db_rd_entry_get(uVar4,auStack_3b8);
              if (iVar2 == 0) {
                if (mesh_debug_switch == '\0') {
                  iVar2 = (int)local_39f;
                }
                else {
                  uVar1 = *(ushort *)(param_1 + 0x10);
                  uVar4 = 0x41b;
LAB_004beea8:
                  printf("[MESH_DEBUG]%s()/%d modify ap_id=%d, rd_id=%d\n",
                         "mesh_set_rd_cfg_to_re_handle",uVar4,(uint)uVar1,uVar5);
                  iVar2 = (int)local_39f;
                }
LAB_004bedc4:
                FUN_004bde50(auStack_364,(int)local_3af,local_3ae,(int)local_3ac,iVar2,local_39e,
                             param_1,uVar7 & 0xff,1,param_3);
              }
              goto LAB_004bec3c;
            }
LAB_004bec5c:
            uVar4 = rdmngr_db_generate_rd_id(local_300,2);
            iVar2 = rdmngr_db_rd_entry_get(uVar4,auStack_3b8);
            if (iVar2 == 0) {
              uVar6 = rdmngr_db_get_band_by_channel((int)local_3ac);
              if ((uVar6 == uVar7) || (local_3ac == -1)) {
                if (mesh_debug_switch != '\0') {
                  uVar1 = *(ushort *)(param_1 + 0x10);
                  uVar4 = 0x44f;
                  goto LAB_004bee5c;
                }
                iVar2 = (int)local_39f;
                goto LAB_004bed10;
              }
              if ((uVar6 != 2) || (uVar7 != 3)) {
                iVar2 = wsta_roam_db_network_mode_get();
                if (iVar2 != 1) {
                  local_358 = 0x24;
                }
                if (mesh_debug_switch != '\0') {
                  uVar6 = (uint)*(ushort *)(param_1 + 0x10);
                  uVar4 = 0x46d;
                  goto LAB_004bed70;
                }
                iVar2 = (int)local_39f;
                goto LAB_004beb94;
              }
              iVar2 = wsta_roam_db_network_mode_get();
              if (iVar2 != 1) {
                iVar2 = apdb_is_support_rrst(*(undefined4 *)(param_1 + 0x40),local_30);
                if (iVar2 == 1) {
                  if ((byte)(*(char *)(param_1 + 0x2d1) - 1U) < 3) {
                    local_358 = 100;
                  }
                  else {
                    local_358 = 0x95;
                  }
                }
                else {
                  local_358 = 0x95;
                }
              }
              if (mesh_debug_switch != '\0') {
                printf("[MESH_DEBUG]%s()/%d modify ap_id=%d, rd_id=%d\n",
                       "mesh_set_rd_cfg_to_re_handle",0x462,(uint)*(ushort *)(param_1 + 0x10),uVar5)
                ;
              }
              iVar2 = (int)local_39f;
              uVar7 = 3;
              goto LAB_004bebb4;
            }
            cVar8 = cVar8 + '\x01';
          }
          else if (local_38 == 2) {
            uVar4 = rdmngr_db_generate_rd_id(local_300,uVar7);
            iVar2 = rdmngr_db_rd_entry_get(uVar4,auStack_3b8);
            if (iVar2 == 0) {
              if (mesh_debug_switch != '\0') {
                uVar1 = *(ushort *)(param_1 + 0x10);
                uVar4 = 0x429;
                goto LAB_004beea8;
              }
              iVar2 = (int)local_39f;
              goto LAB_004bedc4;
            }
LAB_004bec3c:
            if (local_34 == 2) {
              if (local_38 == 3) goto LAB_004bec5c;
              cVar8 = cVar8 + '\x01';
            }
            else {
              cVar8 = cVar8 + '\x01';
            }
          }
          else {
            if (local_34 != 3) goto LAB_004bec3c;
            if (uVar7 == 2) {
              uVar4 = rdmngr_db_generate_rd_id(local_300,2);
              iVar2 = rdmngr_db_rd_entry_get(uVar4,auStack_3b8);
              if (iVar2 != 0) {
                cVar8 = '\x03';
                goto LAB_004bebcc;
              }
              if (mesh_debug_switch != '\0') {
                printf("[MESH_DEBUG]%s()/%d modify ap_id=%d, rd_id=%d\n",
                       "mesh_set_rd_cfg_to_re_handle",0x437,(uint)*(ushort *)(param_1 + 0x10),uVar5)
                ;
              }
              iVar2 = (int)local_39f;
              uVar7 = 2;
              goto LAB_004bed30;
            }
            uVar4 = rdmngr_db_generate_rd_id(local_300,uVar7);
            iVar2 = rdmngr_db_rd_entry_get(uVar4,auStack_3b8);
            if (iVar2 == 0) {
              if (mesh_debug_switch != '\0') {
                uVar6 = (uint)*(ushort *)(param_1 + 0x10);
                uVar4 = 0x440;
                goto LAB_004bed70;
              }
              iVar2 = (int)local_39f;
              goto LAB_004beb94;
            }
            cVar8 = cVar8 + '\x01';
          }
        }
LAB_004bebcc:
        uVar7 = (uint)cVar8;
      }
    }
  }
  return uVar5;
}

