![Electricity Bill Calculator Img](https://github.com/user-attachments/assets/feff6012-bcd8-4cf3-a488-074a05f350de)

# Electricity Bill Calculator (C Project)

This project was developed in my **first semester** to simulate an electricity billing system inspired by Japan’s energy regulation model. The calculator considers region, institution type, energy slabs, and government-imposed surcharges/rebates to compute the final bill. For more details, read the document attached [here](https://github.com/Jian-blue/Electricity_Bill_Calculator_C-Project/blob/main/Documentation.docx).

## Features

- Parses a **Universal Identification (UI)** number like `221-12345-A`
  - Region Code (e.g., 221 for Tokyo)
  - Meter Number
  - Institution Type (e.g., A = 1DK1R Residential)
- Calculates electricity bills based on:
  - **Base energy consumption slab**
  - **Institution-specific rate**
  - **Renewable energy surcharge (1.0005%)**
  - **Government rebate (2.43%)**

## Bill Calculation Structure

### Energy Consumption Slabs

| Consumption (kWh) | Rate (JPY/kWh) |
|-------------------|----------------|
| 0–120             | 20.21          |
| 121–300           | 25.61          |
| >300              | 28.59          |

### Institution Types & Base Fees

| Code | Institution         | Fee (JPY/kWh) |
|------|---------------------|---------------|
| A    | 1DK1R               | 1.10          |
| B    | 1DK2R               | 1.20          |
| C    | Industry Level-1    | 1.60          |
| D    | Industry Level-2    | 1.80          |
| E    | Commercial & Office | 2.00          |
| F    | Temporary           | 1.50          |

### Other Charges

- **Renewable Energy Surcharge**: `Basic amount * 0.010005`
- **Government Rebate**: `Total charge * 0.0243`

---

## Tools Used

- **Language:** C
- **Platform:** Command Line (CLI)

## Author  

**Shafayat Yeamin Jian**  
B.Sc in Computer Science and Engineering  
This project is free to use for anyone — feel free to use it  

---

## How to Run

```bash
# Compile the program
gcc electricity_bill_calculator.c -o bill

# Run the program
./bill
