// func mesh_discover_list_test @ 005d2908 size=1

undefined4
mesh_discover_list_test
          (char *param_1,char *param_2,int param_3,undefined1 param_4,undefined1 param_5,
          char *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  char *__s;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
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
  puVar10 = (undefined4 *)0x0;
  iVar2 = cw_parsed_pkt_create(10);
  if (iVar2 != 0) {
    uRam0074e5dd = 0;
    uRam0074e5de = 0x6a;
    puVar10 = (undefined4 *)cw_pkt_buf_create(0x77);
    if (puVar10 != (undefined4 *)0x0) {
      memcpy((void *)*puVar10,&cw_mesh_discover_req_mesh,0x77);
      *(undefined2 *)((int)puVar10 + 6) = 0;
      *(undefined2 *)(puVar10 + 1) = 0x77;
      iVar3 = capwap_packet_parse(puVar10,iVar1,0,0,&uStack_84);
      if (iVar3 == -1) {
        __s = "parse packet failed. \r";
      }
      else {
        *(undefined4 *)(iVar1 + 0x10) = 9;
        iVar3 = cw_msg_ele_priv_val_get_from_pkt(iVar1,0x76);
        if ((iVar3 == 0) || (iVar3 = cw_priv_mesh_private_control_get(iVar3,1), iVar3 == 0)) {
          __s = "No mesh private discover_result_val. \r";
        }
        else {
          iVar4 = sscanf(param_2,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_74,auStack_70,auStack_6c,
                         auStack_68,auStack_64,auStack_60);
          if (iVar4 == 6) {
            puVar9 = &uStack_74;
            iVar4 = 0;
            puVar5 = puVar9;
            do {
              uVar8 = *puVar5;
              puVar5 = puVar5 + 1;
              iVar6 = *(int *)(iVar3 + 4) + iVar4;
              iVar4 = iVar4 + 1;
              *(char *)(iVar6 + 8) = (char)uVar8;
            } while (iVar4 != 6);
            *(undefined1 *)(*(int *)(iVar3 + 4) + 0x4f) = 1;
            *(undefined1 *)(*(int *)(iVar3 + 4) + 6) = param_4;
            *(undefined1 *)(*(int *)(iVar3 + 4) + 7) = param_5;
            strcpy((char *)(*(int *)(iVar3 + 4) + 0xe),param_6);
            iVar4 = sscanf(param_1,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_74,auStack_70,auStack_6c,
                           auStack_68,auStack_64,auStack_60);
            if (iVar4 == 6) {
              iVar4 = 0;
              do {
                *(char *)(*(int *)(iVar3 + 4) + iVar4) = (char)*puVar9;
                puVar7 = auStack_5c + iVar4;
                uVar8 = *puVar9;
                iVar4 = iVar4 + 1;
                puVar9 = puVar9 + 1;
                *puVar7 = (char)uVar8;
              } while (iVar4 != 6);
              uStack_48 = 0;
              uStack_38 = 0;
              uStack_4c = 1;
              for (iVar4 = 0; iVar4 < param_3; iVar4 = iVar4 + 1) {
                serv_mngr_handle(iVar1,auStack_5c,iVar2);
                *(char *)(*(int *)(iVar3 + 4) + 0xd) = *(char *)(*(int *)(iVar3 + 4) + 0xd) + '\x01'
                ;
              }
              goto code_r0x005d2b20;
            }
          }
          __s = "parameter is wrong";
        }
      }
      puts(__s);
    }
  }
code_r0x005d2b20:
  cw_parsed_pkt_destroy(iVar1);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (puVar10 != (undefined4 *)0x0) {
    cw_pkt_buf_destroy(puVar10);
  }
  return 0;
}

