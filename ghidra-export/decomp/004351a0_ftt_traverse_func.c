// func ftt_traverse_func @ 004351a0 size=1

undefined4 ftt_traverse_func(int *param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  undefined4 uVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  char *pcVar22;
  int iVar23;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined1 auStack_98 [64];
  undefined1 auStack_58 [68];
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  cVar1 = *(char *)(param_2 + 0xa0);
  if ((*(int *)(param_2 + 0x98) == 1) || (*(int *)(param_2 + 0x98) == 3)) {
    if (cVar1 == '\0') {
      pcVar22 = 
      "Ftt tuple entry %d: %s type: %d src_ip: %x/%x dst_ip: %x/%x mac: %x:%x:%x:%x:%x:%x vlan: %d src_port: %d-%d dst_port: %d-%d protocol: %d, iptype: %d\n"
      ;
      iVar18 = *param_1 + 1;
      *param_1 = iVar18;
      puVar20 = *(undefined1 **)(param_2 + 0xa4);
      bVar2 = *(byte *)(param_2 + 0xa0);
      uVar16 = *(undefined4 *)(param_2 + 0xa8);
      puVar21 = *(undefined1 **)(param_2 + 0xb8);
      uVar17 = *(undefined4 *)(param_2 + 0xbc);
      bVar3 = *(byte *)(param_2 + 0xb0);
      bVar4 = *(byte *)(param_2 + 0xb1);
      bVar5 = *(byte *)(param_2 + 0xb2);
      bVar6 = *(byte *)(param_2 + 0xb3);
      bVar7 = *(byte *)(param_2 + 0xb4);
      bVar8 = *(byte *)(param_2 + 0xb5);
      uVar19 = *(undefined4 *)(param_2 + 0xac);
      uVar10 = *(undefined4 *)(param_2 + 0xc0);
      uVar11 = *(undefined4 *)(param_2 + 0xc4);
      uVar12 = *(undefined4 *)(param_2 + 200);
      uVar13 = *(undefined4 *)(param_2 + 0xcc);
      uVar14 = *(undefined4 *)(param_2 + 0xd0);
      uVar15 = *(undefined4 *)(param_2 + 0x98);
      goto code_r0x00435404;
    }
    if (cVar1 != '\x01') {
      return 0;
    }
    pcVar22 = 
    "Ftt url entry %d: %s type: %d src_ip: %x/%x mac: %x:%x:%x:%x:%x:%x vlan: %d url: %s, iptype: %d\n"
    ;
    iVar23 = *param_1 + 1;
    *param_1 = iVar23;
    puVar9 = *(undefined4 **)(param_2 + 0xa4);
    bVar2 = *(byte *)(param_2 + 0xa0);
    uVar16 = *(undefined4 *)(param_2 + 0xa8);
    bVar3 = *(byte *)(param_2 + 0xb0);
    bVar4 = *(byte *)(param_2 + 0xb1);
    bVar5 = *(byte *)(param_2 + 0xb2);
    bVar6 = *(byte *)(param_2 + 0xb3);
    bVar7 = *(byte *)(param_2 + 0xb4);
    bVar8 = *(byte *)(param_2 + 0xb5);
    uVar17 = *(undefined4 *)(param_2 + 0xac);
    iVar18 = param_2 + 0xb6;
    uVar19 = *(undefined4 *)(param_2 + 0x98);
  }
  else {
    if (cVar1 == '\0') {
      memset(auStack_58,0,0x40);
      memset(auStack_98,0,0x40);
      uStack_d8 = 0;
      uStack_d4 = 0;
      uStack_d0 = 0;
      uStack_cc = 0;
      uStack_c8 = 0;
      uStack_ec = 0;
      uStack_e8 = 0;
      uStack_e4 = 0;
      uStack_e0 = 0;
      uStack_dc = 0;
      FUN_00408560(param_2 + 0xa4,2,&uStack_d8);
      FUN_00408560(param_2 + 0xc2,2,&uStack_ec);
      FUN_00408190(uStack_d8,uStack_d4,uStack_d0,uStack_cc,uStack_c8,auStack_58,0x40,"---");
      FUN_00408190(uStack_ec,uStack_e8,uStack_e4,uStack_e0,uStack_dc,auStack_98,0x40,"---");
      puVar20 = auStack_58;
      pcVar22 = 
      "Ftt tuple entry %d: %s type: %d src_ip: %s/%x dst_ip: %s/%x mac: %x:%x:%x:%x:%x:%x vlan: %d src_port: %d-%d dst_port: %d-%d protocol: %d, iptype: %d\n"
      ;
      iVar18 = *param_1 + 1;
      *param_1 = iVar18;
      uVar16 = *(undefined4 *)(param_2 + 0xb4);
      bVar2 = *(byte *)(param_2 + 0xa0);
      puVar21 = auStack_98;
      uVar17 = *(undefined4 *)(param_2 + 0xd4);
      bVar3 = *(byte *)(param_2 + 0xbc);
      bVar4 = *(byte *)(param_2 + 0xbd);
      bVar5 = *(byte *)(param_2 + 0xbe);
      bVar6 = *(byte *)(param_2 + 0xbf);
      bVar7 = *(byte *)(param_2 + 0xc0);
      bVar8 = *(byte *)(param_2 + 0xc1);
      uVar19 = *(undefined4 *)(param_2 + 0xb8);
      uVar10 = *(undefined4 *)(param_2 + 0xd8);
      uVar11 = *(undefined4 *)(param_2 + 0xdc);
      uVar12 = *(undefined4 *)(param_2 + 0xe0);
      uVar13 = *(undefined4 *)(param_2 + 0xe4);
      uVar14 = *(undefined4 *)(param_2 + 0xe8);
      uVar15 = *(undefined4 *)(param_2 + 0x98);
code_r0x00435404:
      printf(pcVar22,iVar18,param_2,(uint)bVar2,puVar20,uVar16,puVar21,uVar17,(uint)bVar3,
             (uint)bVar4,(uint)bVar5,(uint)bVar6,(uint)bVar7,(uint)bVar8,uVar19,uVar10,uVar11,uVar12
             ,uVar13,uVar14,uVar15);
      return 0;
    }
    if (cVar1 != '\x01') {
      return 0;
    }
    memset(&uStack_d8,0,0x40);
    uStack_100 = 0;
    uStack_fc = 0;
    uStack_f8 = 0;
    uStack_f4 = 0;
    uStack_f0 = 0;
    FUN_00408560(param_2 + 0xa4,2,&uStack_100);
    FUN_00408190(uStack_100,uStack_fc,uStack_f8,uStack_f4,uStack_f0,&uStack_d8,0x40,"---");
    puVar9 = &uStack_d8;
    pcVar22 = 
    "Ftt url entry %d: %s type: %d src_ip: %s/%x mac: %x:%x:%x:%x:%x:%x vlan: %d url: %s, iptype: %d\n"
    ;
    iVar23 = *param_1 + 1;
    *param_1 = iVar23;
    uVar16 = *(undefined4 *)(param_2 + 0xb4);
    bVar2 = *(byte *)(param_2 + 0xa0);
    bVar3 = *(byte *)(param_2 + 0xbc);
    bVar4 = *(byte *)(param_2 + 0xbd);
    bVar5 = *(byte *)(param_2 + 0xbe);
    bVar6 = *(byte *)(param_2 + 0xbf);
    bVar7 = *(byte *)(param_2 + 0xc0);
    bVar8 = *(byte *)(param_2 + 0xc1);
    uVar17 = *(undefined4 *)(param_2 + 0xb8);
    iVar18 = param_2 + 0xc2;
    uVar19 = *(undefined4 *)(param_2 + 0x98);
  }
  printf(pcVar22,iVar23,param_2,(uint)bVar2,puVar9,uVar16,(uint)bVar3,(uint)bVar4,(uint)bVar5,
         (uint)bVar6,(uint)bVar7,(uint)bVar8,uVar17,iVar18,uVar19);
  return 0;
}

