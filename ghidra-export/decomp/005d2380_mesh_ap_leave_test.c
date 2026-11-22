// func mesh_ap_leave_test @ 005d2380 size=1

undefined4
mesh_ap_leave_test(undefined4 param_1,undefined2 param_2,char *param_3,char *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  char *__s;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [16];
  undefined1 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_38;
  
  memset(auStack_5c,0,0x34);
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  iVar1 = cw_parsed_pkt_create(9);
  if (iVar1 == 0) {
    return 0;
  }
  puVar8 = (undefined4 *)0x0;
  iVar2 = cw_parsed_pkt_create(10);
  if (iVar2 != 0) {
    uRam0074e691 = 0;
    uRam0074e692 = 0x41;
    puVar8 = (undefined4 *)cw_pkt_buf_create(0x4e);
    if (puVar8 != (undefined4 *)0x0) {
      memcpy((void *)*puVar8,&cw_leave_req_mesh,0x4e);
      *(undefined2 *)((int)puVar8 + 6) = 0;
      *(undefined2 *)(puVar8 + 1) = 0x4e;
      iVar3 = capwap_packet_parse(puVar8,iVar1,0,0,&uStack_84);
      if (iVar3 == -1) {
        __s = "parse packet failed. \r";
      }
      else {
        iVar3 = cw_msg_ele_priv_val_get_from_pkt(iVar1,0x76);
        if ((iVar3 == 0) || (iVar3 = cw_priv_mesh_private_control_get(iVar3,7), iVar3 == 0)) {
          __s = "No mesh private topo change request val. \r";
        }
        else {
          iVar4 = sscanf(param_4,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_74,auStack_70,auStack_6c,
                         auStack_68,auStack_64,auStack_60);
          if (iVar4 == 6) {
            puVar9 = &uStack_74;
            iVar4 = 0;
            puVar5 = puVar9;
            do {
              uVar7 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar6 = (undefined1 *)(*(int *)(iVar3 + 4) + iVar4);
              iVar4 = iVar4 + 1;
              *puVar6 = (char)uVar7;
            } while (iVar4 != 6);
            iVar4 = sscanf(param_3,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_74,auStack_70,auStack_6c,
                           auStack_68,auStack_64,auStack_60);
            if (iVar4 == 6) {
              iVar4 = 0;
              do {
                puVar6 = auStack_5c + iVar4;
                uVar7 = *puVar9;
                iVar4 = iVar4 + 1;
                puVar9 = puVar9 + 1;
                *puVar6 = (char)uVar7;
              } while (iVar4 != 6);
              uStack_4c = 1;
              uStack_48 = param_1;
              uStack_38 = param_2;
              for (iVar4 = 0; iVar4 < param_5; iVar4 = iVar4 + 1) {
                serv_mngr_handle(iVar1,auStack_5c,iVar2);
                *(char *)(*(int *)(iVar3 + 4) + 5) = *(char *)(*(int *)(iVar3 + 4) + 5) + '\x01';
              }
              goto code_r0x005d255c;
            }
          }
          __s = "parameter is wrong";
        }
      }
      puts(__s);
    }
  }
code_r0x005d255c:
  cw_parsed_pkt_destroy(iVar1);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (puVar8 != (undefined4 *)0x0) {
    cw_pkt_buf_destroy(puVar8);
  }
  return 0;
}

