private: System::Void NewQ_Click(System::Object^ sender, System::EventArgs^ e) {


	// Очистка текстового поля для новой очереди
	NewQOut->Text = String::Empty; // Предположим, что у нас есть текстовое поле для вывода новой очереди

	// Получение элементов из OutPutQu
	array<String^>^ elements = OutPutQu->Text->Split(' ');

	// Переменные для хранения максимального значения и нового элемента
	int maxElement = Int32::MinValue;
	String^ newElement = NewElIn->Text->Trim(); // Получаем новый элемент из текстового поля

	// Проверка, является ли новый элемент целым числом
	int newElementValue;
	if (!Int32::TryParse(newElement, newElementValue)) {
		MessageBox::Show("Введите корректное целое число для нового элемента.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Выход из функции, если ввод некорректен
	}

	// Поиск максимального элемента
	for each (String ^ element in elements) {
		int number;
		if (Int32::TryParse(element->Trim(), number)) {
			if (number > maxElement) {
				maxElement = number; // Обновляем максимальный элемент
			}
		}
	}

	// Создание новой очереди с вставкой нового элемента после максимальных
	String^ newQueue = String::Empty;
	for each (String ^ element in elements) {
		newQueue += element->Trim() + " "; // Добавляем текущий элемент в новую очередь
		int number;
		if (Int32::TryParse(element->Trim(), number) && number == maxElement) {
			newQueue += newElement + " "; // Вставляем новый элемент после максимального
		}
	}


	// Удаление первого элемента (если он есть)
	int firstCommaIndex = newQueue->IndexOf(' ');
	if (firstCommaIndex != -1) {
		newQueue = newQueue->Substring(firstCommaIndex + 1); // Удаляем все символы до первого пробела
	}

	// Вывод новой очереди в текстовое поле
	NewQOut->Text = newQueue;

}