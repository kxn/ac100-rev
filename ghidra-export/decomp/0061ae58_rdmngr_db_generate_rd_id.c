// func rdmngr_db_generate_rd_id @ 0061ae58 size=16

uint rdmngr_db_generate_rd_id(int param_1,uint param_2)

{
  return param_2 & 0xf | param_1 << 4;
}

