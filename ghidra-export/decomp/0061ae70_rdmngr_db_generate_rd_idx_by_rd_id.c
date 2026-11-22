// func rdmngr_db_generate_rd_idx_by_rd_id @ 0061ae70 size=16

void rdmngr_db_generate_rd_idx_by_rd_id(uint param_1)

{
  rdmngr_db_generate_rd_idx((param_1 << 4) >> 8,param_1 & 0xf);
  return;
}

