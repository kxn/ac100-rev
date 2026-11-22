// func rrm_group_id_set @ 004ae4e8 size=1

void rrm_group_id_set(ushort param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((short)param_1 == -1) {
    memset(&DAT_00731928,0xff,0x40);
    return;
  }
  if (param_1 < 0x200) {
    uVar2 = (int)(short)param_1 + 1;
    iVar1 = ((int)uVar2 >> 5) + 2;
    (&DAT_00731920)[iVar1] = 1 << (uVar2 & 0x1f) | (&DAT_00731920)[iVar1];
  }
  return;
}

