// func _ntPasswordHash @ 0043dc90 size=300

void _ntPasswordHash(int param_1,int param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_178 [28];
  undefined1 auStack_15c [64];
  undefined1 local_11c [260];
  
  iVar4 = 0;
  memset(local_11c,0,0x100);
  memset(auStack_15c,0,0x40);
  puVar1 = local_11c;
  if (param_2 != 0) {
    do {
      puVar2 = (undefined1 *)(param_1 + iVar4);
      iVar4 = iVar4 + 1;
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 2;
    } while (iVar4 != param_2);
  }
  MD4Init(auStack_178);
  for (uVar5 = 0; uVar5 < (uint)(iVar4 * 2); uVar5 = uVar5 + 0x40) {
    memcpy(auStack_15c,local_11c + uVar5,0x40);
    uVar3 = iVar4 * 2 - uVar5;
    if (0x40 < uVar3) {
      uVar3 = 0x40;
    }
    MD4Update(auStack_178,auStack_15c,uVar3 << 3);
  }
  MD4Final(param_3,auStack_178);
  return;
}

