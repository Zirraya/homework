private: System::Void AddEl_Click(System::Object^ sender, System::EventArgs^ e) {

	q.Clear();
	errorProvider2->Clear();
	System::String^ str = System::Convert::ToString(this->OutPutQu->Text);
	System::String^ chis = System::Convert::ToString(this->NewElIn->Text);
	int num;
	bool _res = Int32::TryParse(chis, num);
	if (chis == "") {
		errorProvider2->SetError(AddEl, "Введите число");
		return;
	}
	else if (!_res) {
		errorProvider2->SetError(NewElIn, "Введено не число");
		return;
	}
	else {
		int x, at, pos = 0;
		at = str->IndexOf(" ");	//позиция первого пробела
		while (at != -1) {	//пока находим пробел
			System::String^ str1 = str->Substring(pos, at - pos);	//считываем число
			pos = at + 1;
			bool res = Int32::TryParse(str1, x);
			q.Enqueue(x);
			at = str->IndexOf(" ", pos);	//ищем след пробел
		}
		q.Enqueue(num);	
		System::String^ str2 = "";
		System::Collections::Generic::Stack<int> buf;
		while (q.Count) {
			buf.Push(q.Peek());
			q.Dequeue();
		}
		while (buf.Count) {
			q.Enqueue(buf.Peek());
			str2 += System::Convert::ToString(buf.Peek()) + " ";
			buf.Pop();
		}

		this->OutPutQu->Text = str2;
	}
}