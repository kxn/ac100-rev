; func sensor_test_db_service_nested_mem_free @ 0x004fef40 size=0x13c
  4fef40:	27bdffe0 	addiu	sp,sp,-32
  4fef44:	afb00018 	sw	s0,24(sp)
  4fef48:	00808021 	move	s0,a0
  4fef4c:	10800047 	beqz	a0,0x4ff06c
  4fef50:	afbf001c 	sw	ra,28(sp)
  4fef54:	8c840004 	lw	a0,4(a0)
  4fef58:	50800005 	beqzl	a0,0x4fef70
  4fef5c:	8e020008 	lw	v0,8(s0)
  4fef60:	0c101f7c 	jal	0x407df0
  4fef64:	00000000 	nop
  4fef68:	ae000004 	sw	zero,4(s0)
  4fef6c:	8e020008 	lw	v0,8(s0)
  4fef70:	5040000c 	beqzl	v0,0x4fefa4
  4fef74:	8e04000c 	lw	a0,12(s0)
  4fef78:	8c440004 	lw	a0,4(v0)
  4fef7c:	10800005 	beqz	a0,0x4fef94
  4fef80:	00000000 	nop
  4fef84:	0c101f7c 	jal	0x407df0
  4fef88:	00000000 	nop
  4fef8c:	8e020008 	lw	v0,8(s0)
  4fef90:	ac400004 	sw	zero,4(v0)
  4fef94:	0c101f7c 	jal	0x407df0
  4fef98:	8e040008 	lw	a0,8(s0)
  4fef9c:	ae000008 	sw	zero,8(s0)
  4fefa0:	8e04000c 	lw	a0,12(s0)
  4fefa4:	50800005 	beqzl	a0,0x4fefbc
  4fefa8:	8e020010 	lw	v0,16(s0)
  4fefac:	0c101f7c 	jal	0x407df0
  4fefb0:	00000000 	nop
  4fefb4:	ae00000c 	sw	zero,12(s0)
  4fefb8:	8e020010 	lw	v0,16(s0)
  4fefbc:	5040000c 	beqzl	v0,0x4feff0
  4fefc0:	8e020014 	lw	v0,20(s0)
  4fefc4:	8c440004 	lw	a0,4(v0)
  4fefc8:	10800005 	beqz	a0,0x4fefe0
  4fefcc:	00000000 	nop
  4fefd0:	0c101f7c 	jal	0x407df0
  4fefd4:	00000000 	nop
  4fefd8:	8e020010 	lw	v0,16(s0)
  4fefdc:	ac400004 	sw	zero,4(v0)
  4fefe0:	0c101f7c 	jal	0x407df0
  4fefe4:	8e040010 	lw	a0,16(s0)
  4fefe8:	ae000010 	sw	zero,16(s0)
  4fefec:	8e020014 	lw	v0,20(s0)
  4feff0:	5040000c 	beqzl	v0,0x4ff024
  4feff4:	8e020018 	lw	v0,24(s0)
  4feff8:	8c440004 	lw	a0,4(v0)
  4feffc:	10800005 	beqz	a0,0x4ff014
  4ff000:	00000000 	nop
  4ff004:	0c101f7c 	jal	0x407df0
  4ff008:	00000000 	nop
  4ff00c:	8e020014 	lw	v0,20(s0)
  4ff010:	ac400004 	sw	zero,4(v0)
  4ff014:	0c101f7c 	jal	0x407df0
  4ff018:	8e040014 	lw	a0,20(s0)
  4ff01c:	ae000014 	sw	zero,20(s0)
  4ff020:	8e020018 	lw	v0,24(s0)
  4ff024:	5040000c 	beqzl	v0,0x4ff058
  4ff028:	8e04001c 	lw	a0,28(s0)
  4ff02c:	8c440004 	lw	a0,4(v0)
  4ff030:	10800005 	beqz	a0,0x4ff048
  4ff034:	00000000 	nop
  4ff038:	0c101f7c 	jal	0x407df0
  4ff03c:	00000000 	nop
  4ff040:	8e020018 	lw	v0,24(s0)
  4ff044:	ac400004 	sw	zero,4(v0)
  4ff048:	0c101f7c 	jal	0x407df0
  4ff04c:	8e040018 	lw	a0,24(s0)
  4ff050:	ae000018 	sw	zero,24(s0)
  4ff054:	8e04001c 	lw	a0,28(s0)
  4ff058:	10800005 	beqz	a0,0x4ff070
  4ff05c:	8fbf001c 	lw	ra,28(sp)
  4ff060:	0c101f7c 	jal	0x407df0
  4ff064:	00000000 	nop
  4ff068:	ae00001c 	sw	zero,28(s0)
  4ff06c:	8fbf001c 	lw	ra,28(sp)
  4ff070:	8fb00018 	lw	s0,24(sp)
  4ff074:	03e00008 	jr	ra
  4ff078:	27bd0020 	addiu	sp,sp,32
