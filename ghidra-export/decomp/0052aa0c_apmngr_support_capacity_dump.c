// func apmngr_support_capacity_dump @ 0052aa0c size=224

void apmngr_support_capacity_dump(void)

{
  ushort *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  ushort *puVar4;
  ushort uVar5;
  ushort *puVar6;
  int iVar7;
  
  printf("capability:\t%08x %08x %08x %08x\n",DAT_007c5490,DAT_007c548c,DAT_007c5488,cap_supp);
  printf("sub capability num:\t%d\n",(uint)sub_cap_num);
  if (sub_cap_num != 0) {
    puts("sub capability:");
    puVar6 = &sub_cap_supp;
    for (iVar7 = 0; iVar7 < (int)(uint)sub_cap_num; iVar7 = iVar7 + 1) {
      puVar4 = puVar6 + 3;
      uVar5 = *puVar6;
      puVar1 = puVar6 + 2;
      pbVar2 = (byte *)((int)puVar6 + 5);
      pbVar3 = (byte *)((int)puVar6 + 7);
      puVar6 = puVar6 + 4;
      printf("\t%d:\t%02x%02x%02x%02x\n",(uint)uVar5,(uint)*(byte *)puVar1,(uint)*pbVar2,
             (uint)*(byte *)puVar4,(uint)*pbVar3);
    }
  }
  return;
}

