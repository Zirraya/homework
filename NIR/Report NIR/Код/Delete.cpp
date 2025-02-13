// Проверка на наличие строк в grdMassiv
	if (this->grdMassiv->Rows->Count == 0) {
		errorProvider3->SetError(grdMassiv, "Тут не строк чтоб их удалить"); // Установка ошибки, если нет строк
		return; // Выход из метода
	}



	// Удаление
	if (!this->grdMassiv->CurrentRow->IsNewRow) {
		int i = this->grdMassiv->CurrentRow->Index;
		this->grdMassiv->Rows->Remove(this->grdMassiv->Rows[i]);
	}