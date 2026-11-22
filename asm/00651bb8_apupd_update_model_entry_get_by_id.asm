; func apupd_update_model_entry_get_by_id @ 0x00651bb8 size=0x28
  651bb8:	27bdffe0 	addiu	sp,sp,-32
  651bbc:	3c02007d 	lui	v0,0x7d
  651bc0:	27a50020 	addiu	a1,sp,32
  651bc4:	afa40020 	sw	a0,32(sp)
  651bc8:	afbf001c 	sw	ra,28(sp)
  651bcc:	0c101fe8 	jal	0x407fa0
  651bd0:	8c44c774 	lw	a0,-14476(v0)
  651bd4:	8fbf001c 	lw	ra,28(sp)
  651bd8:	03e00008 	jr	ra
  651bdc:	27bd0020 	addiu	sp,sp,32
