#include <iostream>
#include <memory>

class DepositUI {
public:
    virtual void RequestDepositAmount() = 0;
};

class WithdrawlUI {
public:
    virtual void RequestWithdrawlAmount() = 0;
};

class TransferUI {
public:
    virtual void RequestTransferAmount() = 0;
};

class Transaction {
public:
    virtual void Execute() = 0; // Método abstracto para ejecutar la transacción
};

class DepositTransaction : public Transaction {
public:
    DepositTransaction(DepositUI& ui) : itsDepositUI(ui) {}
    
    virtual void Execute() override {
        itsDepositUI.RequestDepositAmount();
        // Lógica de la transacción de depósito...
    }

private:
    DepositUI& itsDepositUI;  // Referencia a la interfaz de UI específica
};

class WithdrawlTransaction : public Transaction {
public:
    WithdrawlTransaction(WithdrawlUI& ui) : itsWithdrawlUI(ui) {}

    virtual void Execute() override {
        itsWithdrawlUI.RequestWithdrawlAmount();
        // Lógica de la transacción de retiro...
    }

private:
    WithdrawlUI& itsWithdrawlUI;
};

class TransferTransaction : public Transaction {
public:
    TransferTransaction(TransferUI& ui) : itsTransferUI(ui) {}

    virtual void Execute() override {
        itsTransferUI.RequestTransferAmount();
        // Lógica de la transacción de transferencia...
    }

private:
    TransferUI& itsTransferUI;
};

class UI : public DepositUI, public WithdrawlUI, public TransferUI {
public:
    virtual void RequestDepositAmount() override {
        std::cout << "Solicitando cantidad para depósito..." << std::endl;
    }

    virtual void RequestWithdrawlAmount() override {
        std::cout << "Solicitando cantidad para retiro..." << std::endl;
    }

    virtual void RequestTransferAmount() override {
        std::cout << "Solicitando cantidad para transferencia..." << std::endl;
    }
};

int main() {
    UI gui; // Crear una instancia de la interfaz de usuario (UI)

    // Crear instancias de las transacciones, pasando la UI correspondiente
    DepositTransaction depositTransaction(gui);
    WithdrawlTransaction withdrawlTransaction(gui);
    TransferTransaction transferTransaction(gui);

    // Ejecutar cada transacción
    depositTransaction.Execute();  // Solicita cantidad para depósito
    withdrawlTransaction.Execute(); // Solicita cantidad para retiro
    transferTransaction.Execute(); // Solicita cantidad para transferencia

    return 0;
}
