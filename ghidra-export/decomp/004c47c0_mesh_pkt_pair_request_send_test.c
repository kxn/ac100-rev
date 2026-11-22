// func mesh_pkt_pair_request_send_test @ 004c47c0 size=1

void mesh_pkt_pair_request_send_test
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uStackX_c;
  undefined4 *puStack_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [60];
  
  uStackX_c = param_4;
  memset(auStack_5c,0,0x3c);
  if (param_3 < 0xb) {
    puVar5 = auStack_5c;
    puStack_78 = &uStackX_c;
    for (iVar6 = 0; iVar6 < param_3; iVar6 = iVar6 + 1) {
      iVar1 = sscanf((char *)*puStack_78,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_74,auStack_70,auStack_6c,
                     auStack_68,auStack_64,auStack_60);
      if (iVar1 != 6) goto code_r0x004c48b0;
      puVar2 = &uStack_74;
      iVar1 = 0;
      do {
        puVar3 = puVar5 + iVar1;
        uVar4 = *puVar2;
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 1;
        *puVar3 = (char)uVar4;
      } while (iVar1 != 6);
      puVar5 = puVar5 + 6;
      puStack_78 = puStack_78 + 1;
    }
    mesh_pkt_re_operation_request_send(param_1,param_3,auStack_5c,param_2);
  }
  else {
code_r0x004c48b0:
    puts("parameter is wrong");
  }
  return;
}

