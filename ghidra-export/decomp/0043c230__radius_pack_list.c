// func _radius_pack_list @ 0043c230 size=892

int _radius_pack_list(int param_1,char *param_2,int param_3)

{
  short sVar1;
  byte bVar2;
  byte *pbVar3;
  size_t sVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint local_1a8;
  undefined4 local_1a4;
  byte local_1a0 [112];
  char acStack_130 [256];
  char *local_30;
  int local_2c;
  
  iVar8 = 0;
  pbVar7 = (byte *)(param_3 + 0x14);
  if (param_1 != 0) {
    sVar1 = *(short *)(param_1 + 0x44);
    while( true ) {
      pbVar3 = (byte *)0x0;
      if (sVar1 != 0) {
        pbVar3 = pbVar7 + 1;
        *pbVar7 = 0x1a;
        pbVar6 = pbVar7 + 2;
        pbVar7[1] = 6;
        local_1a8 = (uint)*(ushort *)(param_1 + 0x44);
        pbVar7 = pbVar7 + 6;
        iVar8 = iVar8 + 6;
        memcpy(pbVar6,&local_1a8,4);
      }
      *pbVar7 = (byte)*(undefined4 *)(param_1 + 0x44);
      if (*(int *)(param_1 + 0x44) == 2) {
        sVar4 = 0x70;
        if ((int)*(size_t *)(param_1 + 0x4c) < 0x71) {
          sVar4 = *(size_t *)(param_1 + 0x4c);
        }
        uVar10 = sVar4 + 0xf & 0xfffffff0;
        bVar2 = (char)uVar10 + 2;
        pbVar7[1] = bVar2;
        if (pbVar3 != (byte *)0x0) {
          *pbVar3 = bVar2 + *pbVar3;
        }
        memset(local_1a0,0,0x70);
        memcpy(local_1a0,(void *)(param_1 + 0x50),sVar4);
        sVar4 = strlen(param_2);
        local_30 = acStack_130 + sVar4;
        local_2c = sVar4 + 0x10;
        pbVar3 = pbVar7 + 2;
        pbVar6 = (byte *)(param_3 + 4);
        iVar9 = 0;
        while (iVar5 = iVar9, pbVar7 = pbVar3, iVar5 < (int)uVar10) {
          strcpy(acStack_130,param_2);
          memcpy(local_30,pbVar6,0x10);
          _ac_md5_calc(pbVar7,acStack_130,local_2c);
          iVar9 = iVar5 + 0x10;
          pbVar3 = pbVar7;
          for (; pbVar6 = pbVar7, iVar5 < iVar9; iVar5 = iVar5 + 1) {
            *pbVar3 = local_1a0[iVar5] ^ *pbVar3;
            pbVar3 = pbVar3 + 1;
          }
        }
        param_1 = *(int *)(param_1 + 0x150);
        iVar8 = iVar8 + uVar10 + 2;
      }
      else {
        switch(*(undefined4 *)(param_1 + 0x48)) {
        case 0:
        case 5:
        case 8:
          sVar4 = *(size_t *)(param_1 + 0x4c);
          bVar2 = (char)sVar4 + 2;
          pbVar7[1] = bVar2;
          pbVar6 = pbVar7 + 2;
          if (pbVar3 != (byte *)0x0) {
            *pbVar3 = bVar2 + *pbVar3;
          }
          pbVar7 = pbVar6 + sVar4;
          memcpy(pbVar6,(void *)(param_1 + 0x50),sVar4);
          param_1 = *(int *)(param_1 + 0x150);
          iVar8 = iVar8 + sVar4 + 2;
          break;
        case 1:
        case 2:
          pbVar6 = pbVar7 + 2;
          pbVar7[1] = 6;
          if (pbVar3 != (byte *)0x0) {
            *pbVar3 = *pbVar3 + 6;
          }
          local_1a4 = *(undefined4 *)(param_1 + 0x4c);
          pbVar7 = pbVar7 + 6;
          iVar8 = iVar8 + 6;
          memcpy(pbVar6,&local_1a4,4);
          param_1 = *(int *)(param_1 + 0x150);
          break;
        default:
          param_1 = *(int *)(param_1 + 0x150);
          pbVar7 = pbVar7 + 1;
          break;
        case 6:
          pbVar6 = pbVar7 + 2;
          pbVar7[1] = 10;
          if (pbVar3 != (byte *)0x0) {
            *pbVar3 = *pbVar3 + 10;
          }
          pbVar7 = pbVar7 + 10;
          memcpy(pbVar6,(void *)(param_1 + 0x50),8);
          iVar8 = iVar8 + 10;
          param_1 = *(int *)(param_1 + 0x150);
          break;
        case 7:
          pbVar6 = pbVar7 + 2;
          pbVar7[1] = 0x12;
          if (pbVar3 != (byte *)0x0) {
            *pbVar3 = *pbVar3 + 0x12;
          }
          pbVar7 = pbVar7 + 0x12;
          memcpy(pbVar6,(void *)(param_1 + 0x50),0x10);
          iVar8 = iVar8 + 0x12;
          param_1 = *(int *)(param_1 + 0x150);
        }
      }
      if (param_1 == 0) break;
      sVar1 = *(short *)(param_1 + 0x44);
    }
  }
  return iVar8;
}

