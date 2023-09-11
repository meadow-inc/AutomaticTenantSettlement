add_library(tenant_settlement
    Bill.cpp
    BillProcessor.cpp
    InfoSheet.cpp
    InfoSheetParser.cpp
    LetterCreator.cpp
    Tenant.cpp
)

# Specify the include directories for the tenant_settlement library
target_include_directories(tenant_settlement PUBLIC ${CMAKE_SOURCE_DIR}/include/TenantSettlement)

